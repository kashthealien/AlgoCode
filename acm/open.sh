if [[ $# != 1 ]]; then
    echo "Usage: $0 <problem_name>";
    exit 1;
fi

file=$1;
cd $file;
geany $file.cpp;
geany a;
