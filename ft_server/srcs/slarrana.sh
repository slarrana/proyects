chown -R www-data /var/www/*
chmod -R 755 /var/www/*
mkdir /var/www/sergio

# SSL
mkdir /etc/nginx/ssl
openssl req -newkey rsa:4096 -x509 -days 365 -nodes -out /etc/nginx/ssl/sergio.pem -keyout /etc/nginx/ssl/sergio.key -subj "/C=ES/ST=Madrid/L=Madrid/O=42 Madrid/CN=sergio"

#NGINX
if [ "$autoindex" == 'on' ]; then
	mv ./tmp/slarrana.com /etc/nginx/sites-available/sergio
else
	mv ./tmp/slarrana_autoindex_off.com /etc/nginx/sites-available/sergio
fi
ln -s /etc/nginx/sites-available/sergio /etc/nginx/sites-enabled/sergio
rm -rf /etc/nginx/sites-enabled/default

service mysql start

#MYSQL
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root
echo "CREATE DATABASE phpmyadmin;" | mysql -u root
echo "GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root
echo "update mysql.user set plugin='mysql_native_password' where user='root';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root

#wordpress
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
rm latest.tar.gz
mv wordpress/ /var/www/sergio
mv /tmp/wp-config.php /var/www/sergio/wordpress

#phpmyadmin
cd /tmp/
mkdir /var/www/sergio/phpmyadmin
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz
tar -xvf phpMyAdmin-4.9.5-all-languages.tar.gz --strip-components 1 -C /var/www/sergio/phpmyadmin
rm phpMyAdmin-4.9.5-all-languages.tar.gz
mkdir /var/www/sergio/phpmyadmin/tmp
chown -R www-data:www-data /var/www/sergio/phpmyadmin/tmp
mv /tmp/config.inc.php /var/www/sergio/phpmyadmin/config.inc.php
cd /var/www/sergio/phpmyadmin/sql
echo "source create_tables.sql;" | mysql -u root

service nginx start
service php7.3-fpm start

bash

