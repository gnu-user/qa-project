# copy all the template files as the new <name>_<#> specified
renameall()
{
    # Copy files as a new name
    find . -type f -name "${1}*" | grep -Po '(\.\w+)' | xargs -L1 -I {} cp "${1}"{} "../${1}/${1}_${2}"{}
}