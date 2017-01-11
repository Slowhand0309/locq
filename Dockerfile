# Image for locq dev.
#
FROM slowhand/gcc_cmake:1.0
ENV HOME_DIR /usr/local/locq
WORKDIR $HOME_DIR

COPY . $HOME_DIR

RUN ./build.sh

CMD ["/usr/local/locq/build/locq"]
