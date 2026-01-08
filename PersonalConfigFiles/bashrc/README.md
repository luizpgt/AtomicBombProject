# CDF

cd + fzf 

```sh
# do skip hidden dirs
cdf() { 
  local dir
  dir=$(find ${1:-.} -type d -not -path '*/\.*' 2>/dev/null | fzf +m) && cd "$dir"
}

```
# do not skip hidden dirs
cdfh() { 
  local dir
  dir=$(find ${1:-.} -type d 2>/dev/null | fzf +m) && cd "$dir"
}
