#!/bin/bash

set -eux

I="sudo apt install"

$I libtool

autoreconf -f -i

$I libmxml-dev libv4l-dev automake

./configure

make -j$(nproc --ignore 4)