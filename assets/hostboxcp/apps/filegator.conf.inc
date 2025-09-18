location /filemanager {
    alias /usr/local/hostboxcp/public/filemanager/;
    index index.html index.htm index.php;

    location ~ /(libraries|setup|templates|locale) {
        deny all;
        return 404;
    }
    location ~ /(.+\.(json|lock|md)) {
        deny all;
        return 404;
    }

    location ~ ^/filemanager/(.*\.php)$ {
        alias /usr/local/hostboxcp/public/filemanager/$1;
        fastcgi_pass unix:/run/php-fpm/default-fpm-80.sock;
        fastcgi_index index.php;
        include fastcgi_params;
        fastcgi_param SCRIPT_FILENAME $request_filename;
    }

    location /filemanager/(.+\.(jpg|jpeg|gif|css|png|webp|js|ico|html|xml|txt))$ {
        root /usr/local/hostboxcp/public/filemanager/;
    }
}