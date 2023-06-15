# Maintainer:  Nicholas Wang <me#nicho1as.wang>

pkgname=libjsonbuilder
conflicts=('libjsonbuilder-git')
provides=('libjsonbuilder')
pkgver=20230615
pkgrel=1
pkgdesc="Simple JSON construction library in C."
arch=('x86_64')
source=('jsonbuilder.c' 'jsonbuilder.h' 'Makefile')
license=('GPL3')
sha1sums=('SKIP' 'SKIP' 'SKIP')
depends=('glibc')

pkgver() {
  git log -1 --format="%cd" --date=short | sed 's|-||g'
}

build() {
  cd ${srcdir}/
  make
}

package() {
  install -Dm755 ${srcdir}/libjsonbuilder.so "${pkgdir}"/usr/lib/libjsonbuilder.so
  install -Dm644 ${srcdir}/jsonbuilder.h "${pkgdir}"/usr/include/jsonbuilder.h
}
