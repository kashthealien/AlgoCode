if [[ $# != 1 ]]; then
    echo "Usage: $0 <problem_name>";
    exit 1;
fi

file=$1
mkdir $file;
cd $file;
cp ../template.cpp ./$file".cpp";
touch a;
geany $file".cpp" &
gedit a &

