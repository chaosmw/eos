FROM eosio/producer:eos-ubuntu-18.04-a08ab0d1e2490fdaabaf3900cbe1ade92cbce89d as builder

RUN git clone --depth 1 -b 1.1.7 https://github.com/google/snappy.git \
    && cd snappy \ 
    && mkdir build \
    && cd build \
    && cmake ../ \
    && make install \
    && cd ../../ && rm -rf snappy 

# zookeeper -- for pubsub plugin
COPY cppunit.m4 /usr/local/share/aclocal/
RUN which aclocal \
    && ls /usr/local/share/aclocal

COPY zookeeper.jute.c /tmp/
COPY zookeeper.jute.h /tmp/

COPY zookeeper-release-3.5.4.tar.gz /tmp/
#RUN wget https://github.com/apache/zookeeper/archive/release-3.5.4.tar.gz \
RUN cd /tmp \
    && tar -zxf zookeeper-release-3.5.4.tar.gz \
    && cd zookeeper-release-3.5.4/src/c \
    && ACLOCAL="aclocal -I /usr/local/share/aclocal" autoreconf -if \
    && mkdir generated \
    && cp /tmp/zookeeper.jute.* generated/ \
    && ./configure \
    #&& export CFLAGS="-Wno-error" \
    && make \
    && make install \
    && cd ../../../ \
    && rm -rf zookeeper-release-3.5.4

# jasson -- for pubsub plugin
RUN git clone --depth 1 -b v2.11 https://github.com/akheron/jansson.git \
    && cd jansson \ 
    && mkdir build \
    && cd build \
    && cmake ../ \
    && make install \
    && cd ../../ && rm -rf jansson 

# librdkafka - for pubsub plugin
RUN git clone --depth 1 -b v0.11.4 https://github.com/edenhill/librdkafka.git \
    && cd librdkafka \ 
    && ./configure --enable-static \
    && make \
    && make install \
    && cd ../ && rm -rf librdkafka 

# update 
RUN apt-get update -y && apt-get install -y libcurl4-openssl-dev libusb-1.0-0-dev


