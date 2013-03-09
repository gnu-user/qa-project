BUILD NOTES
==========================

PREREQUISITE
--------------------

1. Make a **lib/** directory in the main POCO library folder so that the compiled library files are stored there


LINUX -- 32 BIT
-----------------------

./configure --prefix=lib/ --cflags=-m32 --cflags=-march=i686 --no-tests --static --omit=Crypto,Data,Net,Util/Units,Util/Units/Internal,XML,Zip
make -j4

./configure --prefix=lib/ --cflags=-m32 --cflags=-march=i686 --no-tests --shared --omit=Crypto,Data,Net,Util/Units,Util/Units/Internal,XML,Zip
make -j4


LINUX -- 64 BIT
---------------------

./configure --prefix=lib/ --cflags=-m64 --no-tests --static --omit=Crypto,Data,Net,Util/Units,Util/Units/Internal,XML,Zip
make -j4

./configure --prefix=lib/ --cflags=-m64 --no-tests --shared --omit=Crypto,Data,Net,Util/Units,Util/Units/Internal,XML,Zip
make -j4



OS X
-----------------------







FIX INCLUDE ERRORS ECLIPSE:
---------------------------------

1. Edit Language.settings.xml in

		workspace-cdt/.metadata/.plugins/org.eclipse.cdt.core/

2. Update the GCC path (ie. from 4.7.1 to 4.7.2)
