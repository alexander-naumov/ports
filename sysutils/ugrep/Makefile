COMMENT =	ultra fast universal grep
CATEGORIES =	sysutils

GH_ACCOUNT =	Genivia
GH_PROJECT =	ugrep
GH_TAGNAME =	v3.9.2

MAINTAINER =	Brian Callahan <bcallah@openbsd.org>

# BSD
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} bz2 c lz4 lzma m pcre2-8 z zstd

# C++11
COMPILER =	base-clang ports-gcc

LIB_DEPENDS =	archivers/lz4 \
		archivers/xz \
		archivers/zstd \
		devel/pcre2

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS =	--disable-avx \
			--disable-neon \
			--without-boost-regex

# All amd64 machines support SSE2, but the same is not true of i386
.if ${MACHINE_ARCH:Mi386}
CONFIGURE_ARGS +=	--disable-sse2
.endif

USE_GMAKE =	Yes

.include <bsd.port.mk>
