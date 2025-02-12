#!/usr/bin/env bash
set -eu

patch_cmd() {
    echo "Applying:: $(basename "$1")"
    patch -Np1 -i "$1"
}

here="$(dirname "$(realpath "$0")")"

pushd "$here"/../gstreamer || exit 1
    patch_cmd "$here"/gstreamer/gstreamer-5509.patch
    patch_cmd "$here"/gstreamer/gstreamer-5511.patch
popd || exit 1

pushd "$here"/../openfst || exit 1
    patch_cmd "$here"/openfst/openfst-879f09d2ac799cca99b78de3442194ebbe29d24a.patch
popd || exit 1
