# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

# This is a vcvarsall.bat replacement, makefile style
# Needs gmake 4.0
# You may encounter Windows builds of gnu make v.3.81. These are full of bugs.
# You should get gnu make at least of version 4.0. 
# Better compile it yourself. Get sources from <https://www.gnu.org/software/make/>

# This script tries to guess paths to compiler and SDK.

# You need some posix tools in path: grep cut 

# Written by Vasiliy Olekhov November 2016.

IS4MAKE=$(findstring z4, z$(MAKE_VERSION))

ifneq ($(IS4MAKE),z4)
$(error Need GNU MAKE 4.0 or higher)
endif

# Visual Studio Toolset. This is toolchain: compiler, linker, etc
# VS120 = VisualStudio 2013
# VS140 = VisualStudio 2015
# Check your environment variable $(VS??COMNTOOLS).
# See also <https://en.wikipedia.org/wiki/Microsoft_Visual_Studio#History>
# You may have different VS installed.
VSTOOLSET?=VS120
# Target platform: 32 or 64
ARCH?=32
# Target configuration: Debug or Release
CONFIG?=Release

# SDK Version. This is library set: standard C library etc.
# You can compile with different Visual Studios and different SDKs
# More info: <https://en.wikipedia.org/wiki/Microsoft_Windows_SDK>
# You may have different SDKs installed. Set here what you need.

#
SDKVER=v8.1 
SDKSUBVER=winv6.3
# Tested with VS2015 (VSTOOLSET=VS140) and VS2013 (VSTOOLSET=VS120):
# SDKVER=v8.1 SDKSUBVER=winv6.3
# SDKVER=v10.0 SDKSUBVER=10.0.14393.0

# VS110  (VisualStudio 2012) and earlier do not support C99 
# (e.g. array initialization by index), don't bother

# VSTOOLSET is commonly set in environment. 
# No matter whether you're running make from VS command prompt or not.
TOOLS=$($(VSTOOLSET)COMNTOOLS)
ifeq ($(TOOLS), )
$(error Toolset not found. Check "$(VSTOOLSET)COMNTOOLS" environment variable)
else
#$(info Using toolset $(TOOLS))
endif

# Guess paths to SDKs
SDKKEY=SOFTWARE\Microsoft\Microsoft SDKs\Windows
SDK64KEY=SOFTWARE\Wow6432Node\Microsoft\Microsoft SDKs\Windows

SDK!=reg query "HKLM\$(SDKKEY)\$(SDKVER)" 2>nul | grep InstallationFolder | cut -c 37-
ifeq ($(SDK), )
#$(info not found in HKLM 32bit)
SDK!=reg query "HKLM\$(SDK64KEY)\$(SDKVER)" 2>nul | grep InstallationFolder | cut -c 37- 
endif
ifeq ($(SDK), )
#$(info not found in HKLM 64bit)
SDK!=reg query "HKCU\$(SDKKEY)\$(SDKVER)" 2>nul | grep InstallationFolder | cut -c 37- 
endif
ifeq ($(SDK), )
#$(info not found in HKCU 32bit)
SDK!=reg query "HKCU\$(SDK64KEY)\$(SDKVER)"2>nul | grep InstallationFolder | cut -c 37- 
endif
ifeq ($(SDK), )
$(error Can not find SDK installation.)
endif
#$(info SDK= [$(SDK)])

SDK := $(subst \,/,$(SDK))

VCROOT=$(subst \,/,$(TOOLS))../../vc
VCINC=$(VCROOT)/Include
#$(info VCROOT=$(VCROOT))

ifeq ($(ARCH), 64)
BIN=$(VCROOT)/bin/amd64
VCLIB=$(VCROOT)/LIB/amd64
SDKLIB=$(SDK)/lib/$(SDKSUBVER)/um/x64
UCRTLIB=$(SDK)/lib/$(SDKSUBVER)/ucrt/x64
else
BIN=$(VCROOT)/bin
VCLIB=$(VCROOT)/lib
SDKLIB=$(SDK)/lib/$(SDKSUBVER)/um/x86
UCRTLIB=$(SDK)/lib/$(SDKSUBVER)/ucrt/x86
endif

$(info Building $(ARCH) bits $(CONFIG))

CC='$(BIN)/cl.exe'
CFLAGS+=/nologo -c 
CFLAGS+=/EHsc
CFLAGS+=/I '$(VCINC)' /I '$(SDK)Include/um'

LD='$(BIN)/link.exe'
LDFLAGS+=/nologo /libpath:'$(VCLIB)' /libpath:'$(SDKLIB)' /libpath:'$(UCRTLIB)'

LIB='$(BIN)/lib.exe'
LIBFLAGS+=/nologo

# Please, check debug flags to meet your needs

# MSVC runtime is compiled-in (static build)
# Otherwise you need spare MSVCR???(D).dll lying 
# somewhere around at runtime.

# Please note that it is strongly advised to match
# runtime versions of library and user code.

# If you need that dynamically linked, change /MTd to /MDd (debug) 
# and /MT to /MD (release)
ifeq ($(CONFIG), Debug)
CDEBUG=/DEBUG /Zi /W3 /WX- /sdl /Od /Oy- /D _DEBUG /RTC1 /MTd /GS /Gd /TC /analyze- 
LDEBUG=/DEBUG /MTd
else
CDEBUG=/MT
LDEBUG=/MT
endif
