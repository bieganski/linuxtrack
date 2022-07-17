#!/bin/bash

set -eux

I="sudo apt install"

$I libtool

autoreconf -f -i

$I libmxml-dev libv4l-dev automake

./configure

make -j$(nproc --ignore 4)

echo "---- copy udev rules.."
sudo cp ./src/99-Mickey.rules /etc/udev/rules.d/
sudo cp ./src/99-TIR.rules /etc/udev/rules.d/

echo "---- reload udev rules.."
sudo udevadm control --reload-rules && sudo udevadm trigger


# check if gui executable was properly created.
if ! [ -f ./src/qt_gui/ltr_gui ]; then
    echo 'ERROR: ./src/qt_gui/ltr_gui not found!'
    exit 0
fi

echo "--- OK, src/qt_gui/ltr_gui found! Invoke it to run the GUI.."
