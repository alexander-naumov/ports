COMMENT=		Python bindings to TagLib audio file tag library

MODPY_EGG_VERSION =	2018.1.1
DISTNAME =		tagpy-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}

CATEGORIES =		audio devel

HOMEPAGE =		https://mathema.tician.de/software/tagpy

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} boost_python${MODPY_VERSION:C/\.//g}-mt m
WANTLIB += tag

COMPILER =		base-clang ports-gcc base-gcc

MODPY_PI =		Yes

MODULES =		lang/python
MODPY_PYBUILD =		setuptools

FLAVORS =		python3
FLAVOR =		python3

LIB_DEPENDS =		audio/taglib \
			devel/boost

CONFIGURE_ARGS +=	--boost-compiler=gcc42 \
			--boost-lib-dir=${LOCALBASE}/lib \
			--boost-inc-dir=${LOCALBASE}/include \
			--taglib-lib-dir=${LOCALBASE}/lib \
			--taglib-inc-dir=${LOCALBASE}/include/taglib \
			--boost-python-libname=boost_python${MODPY_VERSION:C/\.//g}-mt

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${MODPY_BIN} ./configure.py ${CONFIGURE_ARGS}

.include <bsd.port.mk>
