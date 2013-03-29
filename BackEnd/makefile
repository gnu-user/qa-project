###############################################################################
#
#  BackEnd -- BackEnd makefile
#
#  Copyright (C) 2013, Jonathan Gillett, Daniel Smullen, and Rayan Alfaheid 
#  All rights reserved.
# 
# 
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
###############################################################################

# Name of targe
TARGET_NAME := BackEnd

# Source files
JAVA_SOURCE_FILES := src/*.java
JAVA_CLASS_PATH := src/:lib/guava-14.0-rc2.jar
JAVA_BIN_PATH := bin/

# Class files for make clean
CLASS_FILES := *.class

# Remove alias
RM := rm -rf

# Default target
default: BackEnd

# All target
all: BackEnd

# Make invocation
BackEnd:
	@echo 'Building target with Java: $@'
	javac -d $(JAVA_BIN_PATH) -cp $(JAVA_CLASS_PATH) $(JAVA_SOURCE_FILES)
	@echo ''
	@echo -e '\e[0;32mFinished building target: $@ \e[0m'

# Clean
clean:
	@$(RM) $(JAVA_BIN_PATH)$(CLASS_FILES)

