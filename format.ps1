# Collect all files in the current directory and subdirectories
$allFiles = Get-ChildItem -Path ${PWD} -Recurse | 
    Where-Object { -not $_.PSIsContainer -and -not $_.FullName.Contains(".json") -and -not $_.FullName.Contains(".ps1") -and -not $_.FullName.Contains(".git") } | # Exclude directories
    ForEach-Object {
        $relativePath = $_.FullName.Replace($PWD, '').Replace('\', '/')
        "/opt$relativePath"
    }



# Create a string that represents a shell command to format each file
$formatCommands = $allFiles -join " " | ForEach-Object { "clang-format -i --style=microsoft $_" }

# Run the Docker container and pass the shell commands to be executed
docker run --rm --privileged=$true --volume ${PWD}:/opt --entrypoint /bin/sh saschpe/clang-format -c $formatCommands
