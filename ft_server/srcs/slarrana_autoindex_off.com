server {
	listen 80;
	listen [::]:80;
	server_name sergio;
	return 301 https://$host$request_uri;
}

server{

	listen 443 ssl ;
	listen [::]:443 ssl ;
	
	server_name sergio;
	
	ssl_certificate /etc/nginx/ssl/sergio.pem;
	ssl_certificate_key /etc/nginx/ssl/sergio.key;

	root /var/www/sergio;
	index index.html index.htm index.nginx-debian.html index.php;

	location / {
		autoindex off;
		try_files $uri $uri/ =404;
	}

	location ~ \.php$ {
		include snippets/fastcgi-php.conf;
		fastcgi_pass unix:/var/run/php/php7.3-fpm.sock;
	}
}

