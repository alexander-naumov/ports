COMMENT =	bind keys or mouse buttons to shell commands under X11
DISTNAME =	xbindkeys-1.8.7
CATEGORIES =	x11

HOMEPAGE =	https://www.nongnu.org/xbindkeys/xbindkeys.html

# GPLv2+
PERMIT_PACKAGE =	Yes

WANTLIB =	X11 c

# not on MASTER_SITE_SAVANNAH
MASTER_SITES =		${HOMEPAGE:=/../}

MODULES =	x11/tk
RUN_DEPENDS =	${MODTK_RUN_DEPENDS} \
		devel/desktop-file-utils

SEPARATE_BUILD =	Yes

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--disable-guile

NO_TEST =	Yes

pre-configure:
	${MODTCL_WISH_ADJ} ${WRKSRC}/xbindkeys_show

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/xbindkeys.desktop \
		${PREFIX}/share/applications/

.include <bsd.port.mk>
