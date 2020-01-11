#!/bin/sh

get_sarg_expr() {
    case "$(uname -m)" in
    ppc64)
        base="reg(\"r1\")"
        offset=$((112 + $1 * 8))
        ;;
    ppc64le)
        base="reg(\"r1\")"
        offset=$((96 + $1 * 8))
        ;;
    *)
        base="reg(\"sp\")"
        offset=$((($1 + 1) * 8))
        ;;
    esac

    echo "$base + $offset"
}
