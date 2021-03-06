#!/bin/bash
if [ $TRAVIS_OS_NAME = "linux" ]; then
    
sudo apt-get install -y tree

export ARCH=$(arch)

APP=openPSTD
LOWERAPP=${APP,,}

cd ~
mkdir -p $APP/$APP.AppDir/usr/
cd $APP

wget -q https://github.com/probonopd/AppImages/raw/master/functions.sh
chmod +x functions.sh
. ./functions.sh

cd $APP.AppDir
mkdir usr/bin
mkdir usr/lib
mkdir usr/include

echo "created appdir"

cp $HOME/build/Louisvh/openPSTD/OpenPSTD-gui usr/bin/
cp $HOME/build/Louisvh/openPSTD/openpstd.png ./
cp $HOME/build/Louisvh/openPSTD/openpstd.desktop ./
BINARY=./usr/bin/OpenPSTD-gui


get_icon
get_apprun
get_desktop

copy_deps

echo "after copy_deps"
tree -f 
mv home/travis/build/*/openPSTD/*.so usr/lib/x86_64-linux-gnu
cp usr/local/lib/* usr/lib/x86_64-linux-gnu
cp opt/qt55/lib/* usr/lib/x86_64-linux-gnu

# Delete dangerous libraries; see
# https://github.com/probonopd/AppImages/blob/master/excludelist
delete_blacklisted
echo "after blacklist"
tree -f 

#manually add qt plugins, the above scripts don't handle these well
#debug tree first
cd /opt/qt55
tree -f

#get_desktopintegration $LOWERAPP

GLIBC_NEEDED=$(glibc_needed)
VERSION=${RELEASE_VERSION}-glibc$GLIBC_NEEDED
echo $VERSION > ../VERSION

# Patch away absolute paths 
find usr/ -type f -exec sed -i -e 's|/usr|././|g' {} \;
find usr/ -type f -exec sed -i -e 's@././/bin/env@/usr/bin/env@g' {} \;

cd ..
mkdir -p ../out/
generate_type2_appimage

# Upload the AppDir 
transfer ../out/*
echo "AppImage has been uploaded to the URL above; later use GitHub Releases for permanent storage"

fi #}if linux
