FreeImage Scale jni
===================
* javah -jni ImageScale
* implement image scale function by c programming language
* gcc -shared -Ic -fPIC -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/linux" /usr/lib/libfreeimage.so ImageScale.c -o libImageScale.so
* java -Djava.library.path=. ImageScale