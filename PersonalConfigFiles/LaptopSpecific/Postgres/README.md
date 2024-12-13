# Postgres

## Postgres recém instalado:

alterar o usuario linux para o user 'postgres'

```sh
su -i -u postgres
```

usando postgres user

```sh
initdb -D /var/lib/postgres/data
```

iniciar daemon server postgresql.service

```sh
systemctl start postgresql.service
```

more at ::: https://wiki.archlinux.org/title/PostgreSQL
