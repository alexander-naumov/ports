COMMENT=	anonymity service using onion routing

DISTNAME=	tor-0.4.7.13
CATEGORIES=	net
HOMEPAGE=	https://www.torproject.org/

MAINTAINER=	Pascal Stumpf <pascal@stumpf.co>

# BSD
PERMIT_PACKAGE=	Yes

WANTLIB += c crypto event_core event_extra execinfo m pthread ssl z

MASTER_SITES=	https://www.torproject.org/dist/

AUTOCONF_VERSION=2.69
CONFIGURE_STYLE=autoconf
# PIE is already taken care of on a per-arch basis, and we have stack protection
# anyway on FRAME_GROWS_DOWN archs.
CONFIGURE_ARGS=	--with-ssl-dir=/usr \
		--with-libevent-dir="${LOCALBASE}" \
		--disable-gcc-hardening \
		--disable-lzma \
		--disable-zstd
CONFIGURE_ENV+=ac_cv_member_struct_ssl_method_st_get_cipher_by_char=no

LIB_DEPENDS=	devel/libevent2

DB_DIR=		/var/tor
SUBST_VARS+=	DB_DIR

FAKE_FLAGS=	sysconfdir=${PREFIX}/share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/TUNING ${PREFIX}/share/doc/tor/

.include <bsd.port.mk>
