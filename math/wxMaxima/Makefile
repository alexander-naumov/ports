# http://marc.info/?l=openbsd-ports&m=140587945502296&w=2
BROKEN =		allocation error starting socket server

COMMENT =		wxWidgets GUI for the computer algebra system maxima

DISTNAME =		wxMaxima-12.09.0
CATEGORIES =		math
REVISION =		2

HOMEPAGE =		http://wxmaxima.sourceforge.net/

# GPLv2
PERMIT_PACKAGE =	Yes

MASTER_SITES =		${MASTER_SITE_SOURCEFORGE:=wxmaxima/}
MAINTAINER =		Edd Barrett <edd@openbsd.org>

WANTLIB += c m pthread ${COMPILER_LIBCXX} wx_base wx_base_net wx_base_xml
WANTLIB += wx_gtk2_adv wx_gtk2_aui wx_gtk2_core wx_gtk2_html

COMPILER =		base-clang ports-gcc base-gcc

RUN_DEPENDS =		devel/desktop-file-utils \
			math/gnuplot \
			math/maxima
LIB_DEPENDS =		x11/wxWidgets

NO_TEST =		Yes

CONFIGURE_STYLE =	gnu

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/data/wxmaxima.png ${PREFIX}/share/pixmaps
	${INSTALL_DATA_DIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/wxmaxima.desktop ${PREFIX}/share/applications

.include <bsd.port.mk>
