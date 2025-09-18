location /roundcube {
    alias /usr/local/hostboxcp/public/roundcube/;

    location ~ /(README.md|config|temp|logs|bin|SQL|INSTALL|LICENSE|CHANGELOG|UPGRADING) {
        deny all;
        return 404;
    }

    location ~ /(.+\.(json|lock|md)) {
        deny all;
        return 404;
    }

    location ~ ^/roundcube/(.*\.php)$ {
        alias /usr/local/hostboxcp/public/roundcube/$1;
        fastcgi_pass unix:/run/php-fpm/default-fpm-80.sock;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $request_filename;
    }

    location /roundcube/(.+\.(jpg|jpeg|gif|css|png|webp|js|ico|html|xml|txt))$ {
        root /usr/local/hostboxcp/public/roundcube/;
    }
}