#syntax=docker/dockerfile:1.2

ARG baseimage=ubuntu:20.04

######################################
# Builder
######################################
FROM ${baseimage} AS builder

ARG DEBIAN_FRONTEND=noninteractive

RUN set -ex \
    &&  echo 'APT::Install-Recommends "false";' > /etc/apt/apt.conf.d/00-no-recommends \
    &&  echo 'APT::Install-Suggests "false";'   > /etc/apt/apt.conf.d/00-no-suggestions \
    &&  apt-get update \
    &&  apt-get install --yes       \
            ccache                  \
            cmake                   \
            g++                     \
            gcovr                   \
            lcov                    \
            libcurl4-gnutls-dev     \
            libxerces-c-dev         \
            libpthread-stubs0-dev   \
            make                    \
            tzdata                  # for UT DateTimeConverterTest.ConvertToTime_t

WORKDIR /openadr-ven-library

######################################
# Build Artifacts
######################################
FROM builder AS artifacts

COPY . .

RUN --mount=type=cache,target=/root/.ccache,readwrite set -ex \
    &&  cmake -B build -DTEST=1 \
    &&  cmake --build build -j$(nproc)

# ######################################
# # Runtime
# ######################################
# FROM ${baseimage} AS runtime

# ARG DEBIAN_FRONTEND=noninteractive

# RUN set -ex \
#     &&  echo 'APT::Install-Recommends "false";' > /etc/apt/apt.conf.d/00-no-recommends \
#     &&  echo 'APT::Install-Suggests "false";'   > /etc/apt/apt.conf.d/00-no-suggestions \
#     &&  apt-get update \
#     &&  apt-get install --yes   \
#             libcurl4-gnutls-dev \
#             libxerces-c-dev     \
#             tzdata

# WORKDIR /OpenADR-VEN-Library/build

# COPY --from=builder /OpenADR-VEN-Library/build

# # COPY --from=builder /open-adr-ven-library/build/debug/liboadr.so .
# # COPY --from=builder /open-adr-ven-library/build/debug/liboadrsd.so .
# # COPY --from=builder /open-adr-ven-library/build/debug/samplevenmgr .
# # COPY --from=builder /open-adr-ven-library/build/debug/testoadr .
# # COPY --from=builder /open-adr-ven-library/build/debug/xml xml
