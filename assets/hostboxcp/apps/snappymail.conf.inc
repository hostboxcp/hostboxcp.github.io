location /snappymail {
    alias /usr/local/hostboxcp/public/snappymail/;
    index index.html index.htm index.php;

    location ~ /(libraries|setup|templates|locale) {
        deny all;
        return 404;
    }
    location ~ /(.+\.(json|lock|md)) {
        deny all;
        return 404;
    }

    location ~ ^/snappymail/(.*\.php)$ {
        alias /usr/local/hostboxcp/public/snappymail/$1;
        fastcgi_pass unix:/run/php-fpm/default-fpm-80.sock;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $request_filename;
    }

    location /snappymail/(.+\.(jpg|jpeg|gif|css|png|webp|js|ico|html|xml|txt))$ {
        root /usr/local/hostboxcp/public/snappymail/;
    }
}