COMMENT =	Ruby binding for the bcrypt() password hashing algorithm

VERSION =	3.1.18
DISTNAME =	bcrypt-${VERSION}
CATEGORIES =	security

MAINTAINER =	Jeremy Evans <jeremy@openbsd.org>

HOMEPAGE =	https://github.com/codahale/bcrypt-ruby

# MIT
PERMIT_PACKAGE = Yes

MODULES =		lang/ruby

CONFIGURE_STYLE =	ruby gem ext

TEST_DEPENDS =	${FULLPKGNAME}:${BUILD_PKGPATH}
MODRUBY_TEST =	rspec3
MODRUBY_TEST_TARGET = spec

.include <bsd.port.mk>
