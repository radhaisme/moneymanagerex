FROM debian:buster-slim
LABEL maintainer="developers@moneymanagerex.org"
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
      cmake build-essential gettext git pkg-config lsb-release file ccache \
      libwxgtk-webview3.0-gtk3-dev liblua5.3-dev libcurl4-openssl-dev \
      rapidjson-dev && \
    apt-get clean

ENV MMEX_INST_CMD apt install -yqV ./mmex_*.deb
