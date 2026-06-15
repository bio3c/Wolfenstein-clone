#!/bin/bash
set -euo pipefail

# ── Config ──────────────────────────────────────────────
SDL_VERSION="2.28.5"
SDL_TARBALL="SDL2-${SDL_VERSION}.tar.gz"
SDL_URL="https://libsdl.org/release/${SDL_TARBALL}"
VENDOR_DIR="$(cd "$(dirname "$0")" && pwd)/vendor"
SDL_PREFIX="${VENDOR_DIR}/sdl2"
BUILD_DIR="${VENDOR_DIR}/build"

# ── Already installed? ─────────────────────────────────
if [ -f "${SDL_PREFIX}/lib/libSDL2.a" ] && [ -f "${SDL_PREFIX}/bin/sdl2-config" ]; then
    echo "SDL2 ${SDL_VERSION} is already installed at ${SDL_PREFIX}"
    echo "To rebuild, run: rm -rf ${SDL_PREFIX} ${VENDOR_DIR}/${SDL_TARBALL}"
    exit 0
fi

mkdir -p "${VENDOR_DIR}" "${BUILD_DIR}"

# ── Download ────────────────────────────────────────────
if [ ! -f "${VENDOR_DIR}/${SDL_TARBALL}" ]; then
    echo "Downloading SDL2 ${SDL_VERSION}..."
    wget -q --show-progress -O "${VENDOR_DIR}/${SDL_TARBALL}" "${SDL_URL}" || \
        curl -#Lo "${VENDOR_DIR}/${SDL_TARBALL}" "${SDL_URL}"
fi

# ── Extract ─────────────────────────────────────────────
if [ ! -d "${BUILD_DIR}/SDL2-${SDL_VERSION}" ]; then
    echo "Extracting..."
    tar -xf "${VENDOR_DIR}/${SDL_TARBALL}" -C "${BUILD_DIR}"
fi

# ── Build ───────────────────────────────────────────────
echo "Building SDL2 (this will take a few minutes)..."
(
    cd "${BUILD_DIR}/SDL2-${SDL_VERSION}"
    ./configure --prefix="${SDL_PREFIX}" --disable-shared --enable-static --disable-audio 2>&1 | tail -5
    make -j"$(nproc)" 2>&1 | tail -3
    make install 2>&1 | tail -3
)

# ── Done ────────────────────────────────────────────────
echo ""
echo "SDL2 installed at: ${SDL_PREFIX}"
echo ""
echo "Use this in your Makefile:"
echo "  export PKG_CONFIG_PATH := \$(shell pwd)/vendor/sdl2/lib/pkgconfig"
echo "  CFLAGS  = \$(shell PKG_CONFIG_PATH=\$(PKG_CONFIG_PATH) pkg-config --cflags sdl2)"
echo "  LDFLAGS = \$(shell PKG_CONFIG_PATH=\$(PKG_CONFIG_PATH) pkg-config --libs sdl2)"
