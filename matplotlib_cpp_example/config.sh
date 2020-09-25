#!/bin/bash

# Deepnote ONLY
sudo echo "/opt/venv/lib/python3.7/site-packages/" > /usr/local/lib/python3.7/site-packages/usrlocal.pth

mkdir -p builds
cd builds

cmake ..
make
