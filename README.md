# ft_containers
ft_containers subject from 42seoul. Make your own STL containers!

## 두 개의 테스터 사용 방법.

- 모든 컨테이너 헤더 파일의 이름은 예)`vector.hpp`와 같아야한다. 그 외의 파일은 상관 없다.
- tested_path는 테스트 목표 헤더파일이 있는 경로를 가리켜야한다.
- function.sh에 포함된 CFLAGS는 `"-Werror -Wextra -Wall -std=c++98"`거나 `"-Werror -Wextra -Wall -std=c++98" -fsanitize=address -g3"`이어야 한다.
  - 몇몇 파일의 경우 둘 중 하나에서만 제대로 테스트가 되는 경우가 있다. 틀린 경우에 맞게 채점되는 일은 있으나 그 반대는 없다.
- `./run_test vector`와 같이 하나의 컨테이너만 테스트할 수 있다.
- `./run_one srcs/(컨테이너 이름)/(파일이름)`와 같은 방법으로 한 개의 테스트 파일만 돌려볼 수 있다.
  - 끝에 STD를 붙이면 std컨테이너를 테스트 해볼 수 있다. 컴파일이 되지 않아야 맞는 경우를 확인할 때 유용하다.
  - run_one과 run_test의 sanitizer 적용 여부는 별개이다.
  
