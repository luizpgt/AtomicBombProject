# Set up git on a new computer

This guide follows: 
- [Get started/Git basics/Set up Git](https://docs.github.com/en/get-started/git-basics/set-up-git)
- [Caching your GitHub credentials in Git](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git)
- Using [freedesktop.org Secret Service API](https://github.com/git-ecosystem/git-credential-manager/blob/release/docs/credstores.md#freedesktoporg-secret-service-api)

1. Log in on browser
1. Setting your username in Git
    ```
        git config --global user.name "Mona Lisa"
    ```
1. Setting up email in Git
    ```
    git config --global user.email "YOUR_EMAIL"
    ```
1. Follow [Authenticating with GitHub from Git](https://docs.github.com/en/get-started/git-basics/set-up-git#authenticating-with-github-from-git), specifically [Connecting over HTTPS (recommended)](https://docs.github.com/en/get-started/git-basics/set-up-git#connecting-over-https-recommended)
1. Follow [Caching your GitHub credentials in Git](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git), specifically [Git Credential Manager](https://docs.github.com/en/get-started/git-basics/caching-your-github-credentials-in-git#git-credential-manager)
1. Install via Linux Tarbal: [Install Tarball](https://github.com/git-ecosystem/git-credential-manager/blob/release/docs/install.md#tarball) <- link to tarbal download
    ```
    tar -xvf <path-to-tarball> -C /usr/local/bin
    git-credential-manager configure
    ```
1. Save information using `freedesktop.org Secret Service API` via `libsecret` (requires a graphical interface to unlock secret collections): `secretservice` | [freedesktop.org Secret Service API](https://github.com/git-ecosystem/git-credential-manager/blob/release/docs/credstores.md#freedesktoporg-secret-service-api)
    ```
    git config --global credential.credentialStore secretservice
    ```
1. Use git and perform 1 time log in using browser. It will save login information for next sessions.