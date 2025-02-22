COMMENT =	C++ library to parse/format/validate phone numbers

GH_ACCOUNT =	google
GH_PROJECT =	libphonenumber
GH_TAGNAME =	v8.13.3

SHARED_LIBS +=  geocoding                 0.0 # 8.12
SHARED_LIBS +=  phonenumber               0.0 # 8.12

CATEGORIES =	productivity devel

# Apache 2.0
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} absl_bad_optional_access absl_bad_variant_access
WANTLIB += absl_base absl_city absl_civil_time absl_cord absl_cord_internal
WANTLIB += absl_cordz_functions absl_cordz_handle absl_cordz_info
WANTLIB += absl_debugging_internal absl_demangle_internal absl_exponential_biased
WANTLIB += absl_graphcycles_internal absl_hash absl_hashtablez_sampler
WANTLIB += absl_int128 absl_log_severity absl_low_level_hash absl_malloc_internal
WANTLIB += absl_raw_hash_set absl_raw_logging_internal absl_spinlock_wait
WANTLIB += absl_stacktrace absl_strings absl_strings_internal
WANTLIB += absl_symbolize absl_synchronization absl_throw_delegate
WANTLIB += absl_time absl_time_zone boost_atomic-mt boost_chrono-mt
WANTLIB += boost_date_time-mt boost_system-mt boost_thread-mt
WANTLIB += icui18n icuuc m protobuf

MODULES =		devel/cmake

COMPILER =		base-clang ports-gcc

BUILD_DEPENDS =		devel/gtest

LIB_DEPENDS =		devel/abseil-cpp \
			devel/boost \
			devel/protobuf \
			textproc/icu4c

CONFIGURE_ARGS =	-DUSE_STD_MAP=ON \
			-DREGENERATE_METADATA=OFF

WRKSRC =		${WRKDIST}/cpp

do-test:
	${WRKBUILD}/libphonenumber_test

.include <bsd.port.mk>
