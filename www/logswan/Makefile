COMMENT =	fast web log analyzer using probabilistic data structures

V =		2.1.13
DISTNAME =	logswan-$V
REVISION =	0

CATEGORIES =	www

HOMEPAGE =	https://www.logswan.org/

# BSD
PERMIT_PACKAGE =	Yes

# uses pledge()
WANTLIB +=	c jansson m maxminddb

MASTER_SITES =	https://github.com/fcambus/logswan/releases/download/$V/

COMPILER =	base-clang ports-gcc

MODULES =	devel/cmake

LIB_DEPENDS =	devel/jansson \
		net/libmaxminddb

CONFIGURE_ARGS = -DGEOIP2DIR=${LOCALSTATEDIR}/db/dbip

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/logswan
	${INSTALL_DATA} ${WRKSRC}/README.md ${PREFIX}/share/doc/logswan

.include <bsd.port.mk>
