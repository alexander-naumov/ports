COMMENT =	modal webkit-based browser inspired by vim

GH_ACCOUNT =	fanglingsu
GH_PROJECT =	vimb
GH_TAGNAME =	3.6.0
REVISION =	1

CATEGORIES =	www x11

HOMEPAGE =	https://fanglingsu.github.io/vimb/

# GPLv3+
PERMIT_PACKAGE =	Yes

WANTLIB += atk-1.0 c cairo cairo-gobject gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gobject-2.0 gtk-3 harfbuzz intl javascriptcoregtk-4.0
WANTLIB += pango-1.0 pangocairo-1.0 soup-2.4 webkit2gtk-4.0 gmodule-2.0 pthread

LIB_DEPENDS =	www/webkitgtk4

RUN_DEPENDS =	devel/desktop-file-utils

USE_GMAKE =	Yes

CFLAGS +=	-D_BSD_SOURCE
MAKE_ENV =	V=1

FAKE_FLAGS =	PREFIX="${TRUEPREFIX}" \
		MANPREFIX="${WRKINST}/${PREFIX}/man"

.include <bsd.port.mk>
