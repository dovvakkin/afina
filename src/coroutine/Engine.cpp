#include <afina/coroutine/Engine.h>

#include <setjmp.h>
#include <stdio.h>
#include <string.h>

namespace Afina {
namespace Coroutine {

void Engine::Store(context &ctx) {
    char stack_end_here;
    ctx.high =
}

void Engine::Restore(context &ctx) {}

void Engine::yield() {}

void Engine::sched(void *routine_) {}

} // namespace Coroutine
} // namespace Afina
