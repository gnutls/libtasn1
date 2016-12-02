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

# Makefile to build something to static library (.lib)
# requires gnu make 4.0, some posix tools (mkdir, rm)

# set C sources to SRC var, extra libs to EXTRA_LIBS
# set TARGET to library name (e.g. mylibrary.lib)

# Written by Vasiliy Olekhov November 2016.


include vcvars.mk

#$(info Building $(ARCH) bits $(CONFIG))

MKDIR_P=C:/gow/bin/mkdir.exe -p

BUILD_PATH=build/$(ARCH)/$(CONFIG)
BUILD_DIRS+=$(BUILD_PATH) 

OBJS=$(addprefix $(BUILD_PATH)/,$(SRC:.c=.obj))

all: $(BUILD_DIRS) $(BUILD_PATH)/$(TARGET) 

$(BUILD_PATH)/$(TARGET): $(BUILD_DIRS) $(OBJS)
	$(LIB) $(LIBFLAGS) $(OBJS) /OUT:$@ 

$(BUILD_PATH)/%.obj: %.c $(EXTRA_DEPS)
	$(CC) $(CFLAGS) $(CDEBUG) $< /Fo$@

$(BUILD_DIRS): 
	$(MKDIR_P) $@

clean:
	rm -f $(OBJS) $(BUILD_PATH)/$(TARGET)
