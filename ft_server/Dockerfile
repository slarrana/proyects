FROM debian:buster

ENV autoindex on
RUN apt-get update
RUN apt-get -y install 	php7.3-fpm \
			php7.3-common \
			php7.3-mysql \
			php7.3-gmp \
			php7.3-curl \
			php7.3-intl \
			php7.3-mbstring \
			php7.3-xmlrpc \
			php7.3-gd \
			php7.3-xml \
			php7.3-cli \
			php7.3-zip \
			php7.3-soap \
			php7.3-imap \
			wget \
			nginx \
			mariadb-server

COPY ./srcs/slarrana.sh ./
COPY ./srcs/slarrana.com ./tmp/slarrana.com
COPY ./srcs/wordpress.sql ./tmp/wordpress.sql
COPY ./srcs/slarrana_autoindex_off.com ./tmp/slarrana_autoindex_off.com
COPY ./srcs/config.inc.php ./tmp/config.inc.php
COPY ./srcs/wp-config.php ./tmp/wp-config.php


CMD bash slarrana.sh
