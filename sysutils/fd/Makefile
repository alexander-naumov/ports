COMMENT =		simple, fast and user-friendly alternative to 'find'

GH_ACCOUNT =		sharkdp
GH_PROJECT =		fd
GH_TAGNAME =		v8.5.3

CATEGORIES =		sysutils

# MIT/Apache 2.0
PERMIT_PACKAGE =	Yes

WANTLIB +=		${MODCARGO_WANTLIB} pthread

# as devel/cargo MODULES adds DISTFILES, GH_* didn't
DISTFILES +=		${DISTNAME}${EXTRACT_SUFX}

MODULES =		devel/cargo

CONFIGURE_STYLE =	cargo
SEPARATE_BUILD =	Yes

MODCARGO_NO_DEFAULT_FEATURES =	Yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/fd.1 ${PREFIX}/man/man1

.include "crates.inc"

.include <bsd.port.mk>
