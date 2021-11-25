git submodule init
git submodule update


cd curl
./buildconf
./configure --disable-shared --enable-static --prefix=/tmp/curl --disable-ldap --disable-sspi --without-ssl
make && make install
cd ..
gcc -g main-app.c -static $(/tmp/curl/bin/curl-config --static-libs --cflags) -ldl -o connectivity_hub

gcc main-lib.c -o hub_lib.so


cp connectivity_hub <cybellum> 
cp hub_lib.so <cybellum> 
