#!/bin/sh
cat ../29-cortex-forth-a.d/pico-examples/build/cortex-forth-a/cortex-forth-a.uf2  > ./cortex-forth-a.uf2
md5sum ./cortex-forth-a.uf2 > ./cortex-forth-a.uf2.md5.txt

