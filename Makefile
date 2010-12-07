#
# Galois Field Arithmetic Library
# By Arash Partow - 2000
#
# URL: http://www.partow.net/projects/galois/index.html
#
# Copyright Notice:
# Free use of this library is permitted under the
# guidelines and in accordance with the most
# current version of the Common Public License.
# http://www.opensource.org/licenses/cpl.php
#

COMPILER         = -c++
OPTIMIZATION_OPT = -O3
OPTIONS          = -pedantic -ansi -Wall -lstdc++ $(OPTIMIZATION_OPT) -o
OPTIONS_LIBS     = -pedantic -ansi -Wall $(OPTIMIZATION_OPT) -c


CPP_SRC = GaloisField.cpp \
	GaloisFieldElement.cpp \
	GaloisFieldPolynomial.cpp


OBJECTS = $(CPP_SRC:.cpp=.o)


%.o: %.h %.cpp
	$(COMPILER) $(OPTIONS_LIBS) $*.cpp


all: $(OBJECTS) GaloisProto GaloisFieldOut GaloisFieldTest GFPDerivTest GaloisShiftProto

GaloisProto: GaloisProto.cpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) GaloisProto GaloisProto.cpp $(OBJECTS)

GaloisFieldOut: GaloisFieldOut.cpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) GaloisFieldOut GaloisFieldOut.cpp $(OBJECTS)

GaloisFieldTest: GaloisFieldTest.cpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) GaloisFieldTest GaloisFieldTest.cpp $(OBJECTS)

GFPDerivTest: GFPDerivTest.cpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) GFPDerivTest GFPDerivTest.cpp $(OBJECTS)

GaloisShiftProto: GaloisShiftProto.cpp $(OBJECTS)
	$(COMPILER) $(OPTIONS) GaloisShiftProto GaloisShiftProto.cpp $(OBJECTS)

clean:
	rm -f core *.o *.bak *stackdump *#
