COMMENT =	generic test automation framework for acceptance testing

MODPY_EGG_VERSION =	3.1.2

# We could use PyPI, but the test suite is not distributed via that means.
GH_ACCOUNT =	robotframework
GH_PROJECT =	robotframework
GH_TAGNAME =	v${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}
REVISION =	6

CATEGORIES =	devel

# Apache
PERMIT_PACKAGE =	Yes

FLAVORS =               python3
FLAVOR =	python3

MODULES =		lang/python
MODPY_PYBUILD =		setuptools
TEST_DEPENDS =		${FULLPKGNAME}:${FULLPKGPATH}

# There is also a suite of acceptance tests, but they are *very* slow and
# it asks the user to type things and click stuff.
do-test:
	cd ${WRKSRC}/utest && ${MODPY_BIN} run.py

.include <bsd.port.mk>
