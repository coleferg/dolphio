#!/usr/bin/env bash
cp ./build/us/sm64.us.f3dex2.z64 ./tools/krikzz/ED64-XIO/ && ./tools/krikzz/ED64-XIO/romfix64.exe ./tools/krikzz/ED64-XIO/sm64.us.f3dex2.z64 && ./tools/krikzz/usb64.exe -rom=./tools/krikzz/ED64-XIO/sm64.us.f3dex2.z64 -start