source /usr/share/cachyos-fish-config/cachyos-config.fish

function fzf-file-widget
    set -l files (find . -type f 2>/dev/null | fzf --multi --height=40% --layout=reverse)
    if test -n "$files"
        for f in $files
            commandline -i -- (string escape -- $f)" "
        end
    end
end

bind \cf fzf-file-widget

fish_default_key_bindings
set fish_cursor_default block

alias n='nvim'
alias z='~/Downloads/zellij'
alias l="ls -alh"

# overwrite greeting
# potentially disabling fastfetch
#function fish_greeting
#    # smth smth
#end
export PATH="$HOME/.local/bin:$PATH"
