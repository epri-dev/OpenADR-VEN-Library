FROM alpine AS builder
COPY . /open-adr-ven-library
WORKDIR /open-adr-ven-library/build/debug
RUN apk add --no-cache \
    g++ \
    cmake \
    make \
    xerces-c-dev \
    curl-dev \
    tzdata # for UT DateTimeConverterTest.ConvertToTime_t
RUN cmake ../.. -DTEST=1 && make -j$(nproc)

FROM alpine
WORKDIR /open-adr-ven-library/build/debug
RUN apk add --no-cache \
    libstdc++ \
    libcurl \
    xerces-c \
    tzdata # for UT DateTimeConverterTest.ConvertToTime_t
COPY --from=builder /open-adr-ven-library/build/debug/liboadr.so .
COPY --from=builder /open-adr-ven-library/build/debug/liboadrsd.so .
COPY --from=builder /open-adr-ven-library/build/debug/samplevenmgr .
COPY --from=builder /open-adr-ven-library/build/debug/testoadr .
COPY --from=builder /open-adr-ven-library/build/debug/xml xml
