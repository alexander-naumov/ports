# See https://github.com/citra-emu/citra/issues/4571
NOT_FOR_ARCHS =	${BE_ARCHS}

BROKEN-i386 =	undefined reference to operator delete(void*, std::align_val_t), etc.

USE_WXNEEDED =	Yes

COMMENT =	nintendo 3DS emulator

V =		729
DISTNAME =	citra-nightly-${V}
PKGNAME =	citra-0.0.0.${V}
REVISION =	8

CATEGORIES =	emulators

# GPLv2, BSD-2-clause (fmt), LGPL (getopt), MIT (httplib, json, lurlparser),
# "New BSD license" (inih), unlicense/public domain (microprofile),
# BSD-3-clause (nihstro), LGPLv2.1 (soundtouch), BSD-style (xbyak)
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} Qt5Core Qt5Gui Qt5Multimedia Qt5Network Qt5OpenGL
WANTLIB += Qt5Widgets SDL2 c cryptopp enet iconv m

MASTER_SITES =	https://spacehopper.org/mirrors/
EXTRACT_SUFX =	.tar.xz

MODULES =	devel/cmake \
		x11/qt5

# XXX Enable with the next update
#BUILD_DEPENDS =	devel/catch2

BUILD_DEPENDS =	devel/boost
RUN_DEPENDS =	devel/desktop-file-utils \
		misc/shared-mime-info \
		x11/gtk+3,-guic
LIB_DEPENDS =	devel/cryptopp \
		devel/sdl2 \
		net/enet \
		x11/qt5/qtmultimedia

CONFIGURE_ARGS =	-DENABLE_CUBEB=OFF \
			-DENABLE_WEB_SERVICE=OFF

CXXFLAGS +=		-I${LOCALBASE}/include -I${LOCALBASE}/lib/qt5/cmake/Qt5/
MODCMAKE_LDFLAGS =	-L${LOCALBASE}/lib

do-test:
	cd ${WRKBUILD}/src/tests && ./tests

.include <bsd.port.arch.mk>

.if ${PROPERTIES:Mclang}
BUILD_DEPENDS+=	devel/llvm
.endif

.include <bsd.port.mk>
