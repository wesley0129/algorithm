param(
    [string]$date
)

if(-not $date) {
    $date = Get-Date -Format "yyyy-MM-dd"
}

git add . 

$changes = git diff --cached --name-only
if(-not $changes) { 
    Write-Host "No changes"
    exit
}

git commit -m "solve: $date"
git push