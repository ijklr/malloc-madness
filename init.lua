-- bootstrap lazy.nvim, LazyVim and your plugins
require("config.lazy")

-- Do not set vim.opt.clipboard to 'unnamed' or 'unnamedplus' here,
-- as it can trigger unnecessary Kitty confirmation prompts for internal operations.
vim.opt.clipboard = ""

-- Set up OSC 52 as the clipboard provider
vim.g.clipboard = {
  name = "OSC 52",
  copy = {
    ["+"] = require("vim.ui.clipboard.osc52").copy("+"),
    ["*"] = require("vim.ui.clipboard.osc52").copy("*"), -- Optional: For primary selection if needed
  },
  paste = {
    ["+"] = require("vim.ui.clipboard.osc52").paste("+"),
    ["*"] = require("vim.ui.clipboard.osc52").paste("*"), -- Optional
  },
}

vim.o.relativenumber = false
vim.o.number = true

vim.keymap.set("n", "<F10>", function()
  if vim.o.relativenumber then
    vim.o.relativenumber = false
    vim.o.number = false
    vim.o.mouse = ""
  else
    vim.o.relativenumber = true
    vim.o.number = true
    vim.o.mouse = "a"
  end
end, { silent = true })

