FROM vjoke/middle:v1.0.0 as builder
ARG branch=master
ARG symbol=EOS

# clean and update apt
# RUN apt-get clean 
RUN apt-get update

# copy boost
COPY boost_1_71_0.tar.bz2 /tmp/ 
# build EOS
COPY eos eos
# RUN cd eos && echo "$branch:$(git rev-parse HEAD)" > /etc/eosio-version \
#     && cmake -H. -B"/tmp/build" -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ \
#        -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/tmp/build -DBUILD_MONGO_DB_PLUGIN=false -DCORE_SYMBOL_NAME=$symbol \
#     && cmake --build /tmp/build --target install 
RUN cd eos && echo "$branch:$(git rev-parse HEAD)" > /etc/eosio-version \
    cd scripts && chmod +x /eos/scripts/eosio_build.sh && /eos/scripts/eosio_build.sh -oRelease -sEOS -y \
    chmod +x /eos/scripts/eosio_install.sh && /eos/scripts/eosio_install.sh


FROM ubuntu:18.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates && rm -rf /var/lib/apt/lists/*
COPY --from=builder /usr/local/lib/* /usr/local/lib/
COPY --from=builder /eos/build/bin /opt/eosio/bin
COPY --from=builder /eos/Docker/config.ini /
COPY --from=builder /etc/eosio-version /etc
COPY --from=builder /eos/Docker/nodeosd.sh /opt/eosio/bin/nodeosd.sh
ENV EOSIO_ROOT=/opt/eosio
RUN chmod +x /opt/eosio/bin/nodeosd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
ENV PATH /opt/eosio/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin

