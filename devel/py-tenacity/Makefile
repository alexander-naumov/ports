COMMENT =		Python module to retry code until it succeeds

MODPY_EGG_VERSION =	8.0.1
DISTNAME =		tenacity-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION =		1

MAINTAINER =		Mikolaj Kucharski <mikolaj@kucharski.name>

CATEGORIES =		devel

HOMEPAGE =		https://github.com/jd/tenacity

# Apache 2.0
PERMIT_PACKAGE =	Yes

MODULES =		lang/python
MODPY_PYBUILD =		setuptools_scm
MODPY_PI =		Yes

# one test fails if typeguard is missing (currently not in ports)
TEST_DEPENDS =		www/py-tornado${MODPY_FLAVOR}

FLAVORS =		python3
FLAVOR =		python3

.include <bsd.port.mk>
