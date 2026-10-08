function Div(div)
    if div.classes:includes("ansi-escaped-output") then
        return div:walk{
            RawBlock = function(block)
                if block.format == "html" then
                    return pandoc.RawBlock(block.format, string.gsub(block.text, "\n\n", "\n"))
                end
            end
        }
    end
end
