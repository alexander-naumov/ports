COMMENT =		esp8266 and esp32 rom bootloader communication tool

MODPY_EGG_VERSION =	4.3
DISTNAME =		esptool-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
REVISION =		1

CATEGORIES =		devel
HOMEPAGE =		https://github.com/espressif/esptool

#GPLv2
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_PYBUILD =		setuptools

RUN_DEPENDS +=		devel/py-serial${MODPY_FLAVOR} \
			security/py-aes${MODPY_FLAVOR} \
			security/py-ecdsa${MODPY_FLAVOR}

FLAVORS =		python3
FLAVOR =		python3

NO_TEST =		Yes

.include <bsd.port.mk>
